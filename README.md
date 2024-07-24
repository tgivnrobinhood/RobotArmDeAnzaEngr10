Tabletop Robot Arm for De Anza Intro To Engineering Final Project

This code is desinged to control a small robotic arm consisiting of servo's as the moving parts.

app.js runs everything, obviously. It opens index.html as a locally hosted site that contians the UI. Said site communicated via socket with the node server written in app.js which then sends what UI were pressed to the arduino through serialport. The arduino procceses this and commands the actual servos.

Thank you to Adam Thomas for his guide.

