The goal of this project was to create a simple yet realistic particle collision simulation. 
We used C++ for it's efficiency and the SFML library for graphics.

### To run:
- Open project files in IDE of choice and using the command line navigate to build folder
- Run 'make' command
- Run ./balls executable

### Challenges: <br />
We initially attempted to use kinematics equations to calculate tragectories and more complicated equations to calculate post collision velocities.
This resulted in unpredictable behaviour and poor performance scaling as the program would begin lagging at ~200 objects. After doing some research we 
decided to switch entirely to Verlet integration. This fixed both issues, as the simpler calculations were both more robust and efficient, and now the program runs
smoothly even up to ~1500 objects. 

### Future Improvements: <br />
The final step in this project would be to integrate the use of threads to further improve efficiency. The goal is to be able to handle at least 5000 objects smoothly.
<p align="center">
<img src="https://private-user-images.githubusercontent.com/55002913/325752543-64aac3f2-8442-4b3d-a0da-171f5705d9b4.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTQwNzUyMTIsIm5iZiI6MTcxNDA3NDkxMiwicGF0aCI6Ii81NTAwMjkxMy8zMjU3NTI1NDMtNjRhYWMzZjItODQ0Mi00YjNkLWEwZGEtMTcxZjU3MDVkOWI0LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQwNDI1VDE5NTUxMlomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTRmYTM3N2E5ODVjZDMzY2QyZDYxNjEwZmNjOWU0NDcwOTQ3Y2ViNDBlYjJiZTM5ODUyZTIyMGE2MTA1NjBmNTAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JmFjdG9yX2lkPTAma2V5X2lkPTAmcmVwb19pZD0wIn0.V2Y0I2epy41nRyu7Td3OPq6xHuE9A0YLTVwRcr25fWA" alt="drawing" width="400"/>
</p>
