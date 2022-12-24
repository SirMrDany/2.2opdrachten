# Opdrachten week 3

## Opdracht RegEx
In de file apache-access-log.txt vind je een access-log.
Schrijf een regex die mailadressen herkent van het bedrijf “shaw”. Het bedrijf staat zowel
onder de tld com en .net geregistreerd.

In de basis volgt het bedrijf Shaw de conventies van email-naamgeving van RFC 822.
Daarboven op hebben ze de volgende naamgevingssystemetiek.
-	Generieke opbouw van een mailadres bij Shaw is: <mailnaam>@shaw.com of <mailnaam>@shaw.net
-	Voor de <mailnaam> geldt:
o	Minimaal 2 karakters (karakter= cijfer, letter en speciale tekens), maximaal 99
o	Op laatste positie staat of een letter (“a” t/m “z” , “A” t/m “Z”), of een cijfer(“0” t/m “9”)
o	Op andere posities geen cijfers toegestaan, wel letters of de speciale tekens “.”, “_” en “-“
o	Andere speciale tekens geheel niet toegestaan


De regex kun je als volgt controleren:
grep -E -o "<YOUR_REGEX>" access_log

Mijn Regex:
[a-zA-Z0-9_\-\.]{1,98}[a-zA-Z0-9](@shaw.com|@shaw.net)

## Opdracht monitoring en logging
