#FFT Project Documentation 

## What I did: 

For this project I created an audio-reactive visual system using FFT. The general base of my project was to take the sound frequencies using FFT and visualize them as shapes that rotate and change size and color based on the audio sound and spectrum. 
I then added in GUI to go beyond the template originally given to use! This made it so when the project is running a person can control the sound's volume, visual decay, shape rotation, and shape size using GUI in a collaborative way. 
The last thing I wanted to do with this project, was to incorporate some fun visuals! I changed the visuals and found new things in some github repos. In the end, the visuals were arranged to be revolving in a circle. There is a mix of 2D shapes (circle and square) put in a 3D space.

## How I did it : 

1. setup function - sets up the frame rate and sync project. 
- for audio setup I added my audio file "bassbounce.wav" and made sure there was a play and loop function so the sound would continue.
- for GUI setup I added the following: 
        audioamplitude to control volume of sound (default 0.5).
        visualdecay to control how quick elements go (0.5)
        shapeRotation to control rotation of the shapes (default 0).
        shapeSize to control size of shapes (default 50).
- Then the fft function creates an array to keep frequency from the sound, with 128 frequency bands, 64 bands for visuals. 
- Lastly, under the 3D Camera setup is (cam.setDistance(400)) which has the camera's distance come from the center of the screen.
        
2. Update Function- Updates audio data and FFT
- Audio data function uses following: 
        ofSoundUpdate() to refresh sound consistantly 
        sound.setVolume which sets volume based on the audioamplitude GUI.
        float *soundSpectrum = ofSoundGetSpectrum(bands) which takes current sound of the data from the audio file and keeps it in soundSpectrum.
- FFT decay and update:
        The loop goes through each frequency band (bands = 64), updating the fft[] array:
        fft[i] *= visualdecay decreases the values over time to create a fade 
3. draw fuction - creates shapes, set backround, drawings, and rotations 
- Background and blending:
        - ofBackground(10, 10, 20) sets a dark background.
        - ofEnableBlendMode(OF_BLENDMODE_ADD) makes blending mode, which makes visuals brighter.
- 3D camera:
        *cam.begin() creates a 3D camera, allowing for 3D transformations.
- Shape drawing:
        - ofPushMatrix() and ofPopMatrix() keeps matrix so visuals are centered and reset after drawing.
        - The visuals are centered using ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2).
- Shape rotation:
        - ofRotateDeg(shapeRotation) applies rotation to all the shapes based on the shapeRotation GUI slider.
- Shape arrangement and drawing:
        - The loop goes through each frequency band (bands = 64)
        - ofMap(i, 0, bands, 0, TWO_PI) creates circle foramtion 
        - The shapes are positioned based on frequency data (fft[i]), using (x, y) to make circle.
        - z-axis added for dynamic movement
        - shapeCurrentSize scales  size of the shape based on the current FFT value and the shapeSize slider.
        - The color of each shape is set based on the frequency band and FFT value, creating bright colors.
        - Shapes are drawn as either rectangles or circles, switching based on if the index i is even or odd.
- Camera end:
        - cam.end() ends the 3D camera 
- GUI drawing:
        - gui.draw() creates the GUI panel with the sliders for a person to control the visuals and sound.

## Problems I faced : 

error 1: when setting up cam.begin in cpp it would not run 
error 2: switching .wav audio file 
error 3: playing with ofRotateDeg(shapeRotation) because it would not run correctly with the GUI
error 4: basic set up and update on visuals 

## How I overcame my problems : 

error 1: I had to call the .cam the correct way in order for it to show in my shape fft
error 2: I had to find my original audio file that I had in this project from when I was first testing it out and make the switch, I realized later my only issue was not calling the correct file name 
error 3: I forgot to actually call the rotation in my draw function 
error 4: I olayed around a bunch with different shapes but once I added the GUI everything fell into place where I liked it!


## What code/examples/information I used from outside sources (github)

I found it helpful to look into Github public repositores for more information, examples of code I could use for my FFT audio visualization and openFrameworks, and advanced techniques I could add and learn! 

**1st reasourse: ofxFFT by Kyle McDonald** this repo has two FFT libraries for oF that I was intrested in. (FFTW and KISS FFT) I used some examples that they had like example-visualize to understand how to visualize audio data using FFT. This mainly helped me understand how FFT can take audio-reactive visuals with more control. 
**2nd reasourse: ofxFFTPlotter by hosackm** this repo helped me with FFT audio plotting. I got simple examples of how and where I can put FFT data and visuals, connecting FFT with graphics, and creating waves. 
**3rd reasourse: Music Visualizer by diproray in oF** helped me learn how to create 2D and 3D sound visuals through FFT and other audio features. I was able to find more detailed visuals like graphs or movements in 2D and 3D! 

These repositories helped me find more detailed examples and libraries to experiment with to help the code I already had in my project by adding more audio-reactive elements, visual decay, and even 3D transformations.

#Where to find the code I used: 

https://github.com/kylemcdonald/ofxFft
https://github.com/hosackm/ofxFFTPlotter
https://github.com/diproray/music_visualizer
