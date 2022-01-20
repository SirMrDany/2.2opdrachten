# Opdrachten Practicum week 1

Opdracht scripting

Stel dat je een smartphone hebt waarmee je mooie foto’s kunt maken en dat dan ook dagelijks veel
doet. De foto’s worden door middel van een cloud oplossing gedeeld en gesynchroniseerd met je
laptop. Na een jaartje foto’s knippen valt het je op dat je veel tijd kwijt bent met de foto’s in
verschillende mapjes te zetten (dit doe je zodat je ze snel terug kunt vinden).

Je wilt nu een eenvoudig tooltje om foto’s automatisch te verplaatsen naar één of meerdere 
mappen. Je hebt daarop besloten om deze zelf te maken met behulp van een Linux shell script.

Het script accepteert twee parameter.

- De eerste parameter is de directory waar de foto’s staan.
- De tweede parameter bestaat uit de aanduiding “maand” of “week”.

Als het script wordt gestart zal deze afhankelijk van de tweede parameter, de foto’s die ouder zijn dan de gekozen optie naar een (nieuw te creëren) folder verplaatsen.
Bijvoorbeeld als er als tweede parameter “week” wordt gekozen, dan verplaatst het script de foto’s
in de map naar (nieuw te creëren) submappen met het corresponderende weeknummers.

Bij het verplaatsen wordt het origineel pas gewist als er gecontroleerd is of de kopieerslag succesvol
is geweest. Dit los je op door de hash (bv. m.b.v. MD5sum) van beide foto’s te vergelijken. Als deze
gelijk zijn dan pas verwijder je de foto van de originele locatie.
