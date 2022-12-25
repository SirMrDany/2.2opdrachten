// basic_tasks.ino but name changed to opdracht 5
// MIT license 

#define LED1 12
#define LED2 13
#define LED3 14

struct s_led {
  byte gpio;
  byte state;
  unsigned napms;
  TaskHandle_t taskh;
};

static s_led leds[3] = {
  {LED1, 0, 500, 0},
  {LED2, 0, 250, 0},
  {LED3, 0, 750, 0}
};

static void led_task_func(void *argp){
  s_led *ledp = (s_led*)argp;
  unsigned stack_hwm = 0, temp;
  
  delay(1000);

  for(;;){
    digitalWrite(ledp->gpio, ledp->state ^= 1);
    temp = uxTaskGetStackHighWaterMark(nullptr);
    if(!stack_hwm || temp < stack_hwm){
      stack_hwm = temp;
      printf("Task for GPIO %d has stack hwm %u\n",ledp->gpio,stack_hwm);
    }
    delay(ledp->napms);
  }
}

void setup(){
  int app_cpu = 0;
  delay(500);

  app_cpu = xPortGetCoreID();
  printf("App_cpu is %d (%s core)\n",app_cpu,app_cpu > 0 ? "Dual" : "Single");

  printf("LEDs on gpios: ");
  for(auto& led : leds){
    pinMode(led.gpio,OUTPUT);
    digitalWrite(led.gpio,LOW);
    xTaskCreatePinnedToCore(
      led_task_func,
      "led_task",
      2048,
      &led,
      1,
      &led.taskh,
      app_cpu
     );
     printf("%d ",led.gpio);
  }
  putchar('\n');
}
int ctr = 0;
void loop() {
  printf("counter = %d\n", ctr);
  if (ctr == 10) {
    vTaskSuspend(leds[0].taskh);
    printf ("Suspend Task %d",(ctr/3));
  }
  if (ctr == 13) {
    vTaskSuspend(leds[1].taskh);
    printf ("Suspend Task %d",(ctr/3));
  }
  if (ctr == 16) {
    vTaskSuspend(leds[2].taskh);
    printf ("Suspend Task %d",(ctr/3));
  }
  if (ctr == 25) {
    vTaskResume(leds[0].taskh);
    vTaskResume(leds[1].taskh);
    vTaskResume(leds[2].taskh);
    ctr = 0;
  }
  delay(1000);
  ctr++;
}