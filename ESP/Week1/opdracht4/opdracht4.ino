void setup() {
  printf("Opdracht 4 boekvragen\r\n1. How do you obtain the current executing task handle? \r\n xTaskGetCurrentTaskHandle()\r\n");
  printf("2. How do you give up the CPU to another Task?\r\n taskYIELD()\r\n");
  printf("3. Which CPU core do application programs execute on for the ESP32?\r\n CPU (1), CPU(0) runs the housekeeping tasks\r\n");
  printf("4. What is the name of the default task provided by the Arduino Environnement?\r\n The task is called xTaskCreatePinnedToCore, which creates the loop etc.\r\n");
  printf("5. What FreeRTOS function is used to suspend one task?\r\n vTaskSuspend() is used.\r\n");
  printf("6. Can a task delete itself, and if so, how?\r\n Yes, vTaskDelete(nullptr);\r\n");
  printf("7. When is the task's stack released when a task deletes itself? Immediatly or later during the IDLE task?\r\n The task terminates immidiatly, but the memory is released after the IDLE task executes\r\n");
  printf("8. What causes the preemption in FreeRTOS for ESP32?\r\n The Timer\r\n");
  printf("9. How often do the ESP32 tick interrupts occur?\r\n 80.000.000 per seconde (80Mhz)\r\n"); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
