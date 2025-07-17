
# C++ Text-Based RPG Engine

Project Overview:

	This is a console-based text RPG created almost entirely from scratch within C++ as a personal project to :

	 -Practice **Object Oriented Design vs. Data Driven Design**
	 -Strengthen **C++ Architecture, memory management, and system design** skills.
	 -Explore **Inventory Systems, Turn-Based Combat Structure, Save/Load File Handling**
	 -Learn **ECS-Design, 

	 This was almost entirely self-taught/researched project, and all code was made by me. 

Motivations:

	I created this project to 

	-Practice/Reinforce advanced C++ class design and memory management
	-Explore basic game design architecture such as data driven design, as well as ECS fundementals
	-Build a portfolio piece showcasing game systems programmming skills outside coursework
	-Have fun! I've always wanted to work on game design, and this really was a passion project for me.



Key Features:

	Player & Inventory System

		Player class with dynamic attributes (HP, mana, stats)

		Inventory with stackable items tracked via InventoryEntry structs

		Unique Items with type-based effects (weapons, armor, consumables)

	Turn-Based Combat System

		Enemies with condition-based decision making

		Data-driven action system with type enums and (planned) lambda evaluation

	Map & Navigation

		OOP location-based navigation system with directional connectivity

		(Planned) Dynamic events and interactions per location

	Save/Load System

		(In development) Save files storing player stats, inventory IDs, and location data

		Planned unordered_map database for item initialization

	Not Created by Me:
			- Random Number generator 
			- Debug Logger
			- nlohmann json toolkit | check it out on github - https://github.com/nlohmann/json



About the Author: 
	
	Connor LaMora

		- Electrical and Computer Systems Engineering student at Rensselaer Polytechnic Institute
		- Passionate about Game Design, Cybersecurity, and all things programming
		- For questions or collaboration inquiries, contact me at lamorc2@rpi.edu or connorlamora@gmail.com