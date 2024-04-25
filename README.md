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
