# Cs125Project
A project for CS125, this is a murder mystery game with combat elements

Outline of the code:

# Start
- User is a detective and is investigating the murder of __
    - The story line will be set 
    - Indroduce the 5 suspects
    - Introduce the layout of where the murder happened (ASCII art)
- In a seperate function the murderer, room, and weapon will be decided (using RAND)     

# Finding the Room: 
- User will explore each room, each will give a short description, be displayed using ASCII art.
- Based on which room is chosen, an additional statement within the description will be added, a clue.
    -  
    - The user will have to guess what room the murder happened
       - If the user choses incorrectly, they must go through the remaining rooms for more information
            - For each incorrect guess, they should receive more clues but they should have less of an advantage in combat    
       - If they guess correctly they will then continue their search for weapons

# Finding the Weapon:
- User will explore what weapons are in the room that the murder occured
- The user will notice different things about each weapon
    - The user will have to guess the murder weapon
       - If the user guesses incorrectly then the murder will use that weapon in combat

# Finding the Person:
- User will interogate who they feel is nessecary (they can only interogate 3 out of 5 people)
- After this information is given a clue will appear to the user (doesn't depend if they interviewed the correct person)
    - The user will now guess the person
        - If the user guesses correctly they get an advantage in the fight (they begin the take-down, and choose their weapon)
        - If the user guesses incorrectly they get a disadvantage, the murderer attacks them first and they will not be able to choose their weapon 

# The Fight:
- The location will be coded and displayed using ASCII art. 
- The person, and weapon will be displayed using ASCII art. Each person will have a unique look similar to CLUE.
- The user will be dispayed, they will be equipped with a weapon which will also be displayed using ASCII art.
- There will be an option for one-player or two-player, with player two playing as the murderer
- Combat
    - Both parties begin with 10 health.
    - Turn-based combat
    - Three different types of attacks
        - high (head)
        - mid
        - low
    - The attacking person will choose where to attack, the defender will choose where to block. 
    - Damage is based off the attacker's damage value, as well as unique traits of each weapon which will be described in the user guide at any time.
        - Blocked attacks will deal reduced damage
        - Unblocked attacks will deal regular damage
            - Potential for critical hits based on location of attack
                - For example, 60% chance of critical for high attacks, 40% for mid attacks, 20% for low attacks 
                - This would create incentives for users to block and attack high, opening the potential for mind games
    - Combat ends when either party reaches 0 hp 
    - The combat will likely be against the computer which will "control" the person, attacking randomly in either high, middle, or low
    - For one-player, the murderer will attack in random locations but is more likely to attack high

# The Ending:
- The user will be granted a victory scene, if the murderer wins they will be displayed a unique screen based on their character, if the detective wins they
- will be granted two scenes, one for them arresting the murderer and another afterwards in which they are given a medal. ASCII art.
