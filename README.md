# Stranger Internet Of Things
Stranger Things A-Z board powered by Particle Photon

Integrates with IFTTT easily to read out Tweets, SMS messages or any other input messages up to 63 characters. Does not support ampersand. (&)

## Instructions

1. Install demogorgon.ino to a Particle Photon using the attached schematic.
2. Register a new recipe in IFTTT to call a function. Call function 'stranger' using the trigger.
3. When the IFTTT recipe triggers, the input text will be read out on the LED string. Update the getCharAddress function to your own LED to ABC mappings.
