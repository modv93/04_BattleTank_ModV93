# 04_BattleTank_ModV93
Open world head to head tank battle with simple AI, terrain and advanced control system in Unreal Engine 4

## Battle Tanks
[Battle Tanks by ModV93](https://github.com/modv93/04_BattleTank_ModV93)

### Commits 
* 01_Readme_markup
* 01_Readme_markup_2
* 01_Readme_markup_3
* 02 Github repo setup
* 03 Landscape Start
* 03 Landscape Start [markup]
* 04 Landscape version_1
* 05 Landscape Color  materials
* 06 Landscape iteration 1 complete
* 07 Tank BluePrint complete and placed
* 08 Improved tank blueprint, Aim Azimuth and Aim Elevation setup
* 09 Third Person Camera setup finish (Changes in BP)
* 10 Main menu UI elements added
* 11 Game iteration complete, TankPlayerController_U added
* 12 TankPlayerController[original] tank possession setup
* 13 AI tank controller possession setup
* 14 AI player spotter setup
* 15 Player ControllerTick setup for aiming
* 16 GetSightRayHitLocation setup for aiming through crosshair
* 17 Find Cross hair position pixel coordinates 
* 18 Get world looking direction setup
* 19 Line Trace for Cross hair setup
* 20 AI tanks to aim at Player tank setup
* 21 Tank Aiming component class setup, logs redirected 
* 22 Barrel component setup and reporting 
* 23 Suggest Projectile velocity function call complete 
* 24 Barrel movement basics setup
* 25 Failed start
* 26 Final Go Ahead commit
* 27 Elevation aiming complete
* 28 Next commit for head
* 29 Turret rotation phase 1 complete
* 30 Fire, Projectile and Projectile BP setup
* 31 Projectile spawn complete
* 32 Projectile launch complete
* 33 AI Tanks fire and fire delay complete
* 34 EditAnywhere changed to EditDefaultsOnly
* 35 Quit button for main menu complete
* 36 L/R Throttle setup
* 37 Tank hovering and materials setup
* 38 Fly by wire start [Tank movement component]
* 39 Fly by wire, forward movement setup
* 40 Manual Tank movement complete
* 41 Tank AI RequestDirectMove setup
* 42 AI Tank forward movement [Dot product]
* 43 AI Tank rotate setup [Cross product]
* 44 TankMovement code cleanup
* 45 Aim reticle blueprint variable setup
* 46 ENUM setup for reticle colors in blueprint / CPP
* 47 Tank aiming from Blueprint, refactored CPPs. Aiming still BROKEN
* 48 BlueprintImplementableEvent setup, crosshair still not changing.
* 49 Assertion used for protecting pointers [ensure]
* 50 Green | Aiming working, ready to decouple for new architecture
* 51 Aiming architectural dependencies refactored.
* 52 Architecture refactored, diamond dependencies removed. Working aiming and fire
* 53 Cross-hairs status complete, reticle changes colour upon the respective state
* 54 Programmatic sideways friction implied
* 55 OnHit event added in CPP
* 56 Tank in air forces disabled
* 57 Tank aiming improved to follow shortest path to aim
* 58 Tank AI BP created and acceptance radius game tested.
* 59 Ammo display and counter setup
* 60 Auto mortars setup and working
* 61 .gitignore [ Updated ]
* 62 .gitignore updated and starter content removed
* 62.5 gitignore updated
* 63 Preparing for particle systems, projectile_BP setup in cpp
* 64 Particle systems setup, smoke trail and blast working
* 65 Impact blast for projectiles tweaked and working
* 66 Explosion impulse implied on hit tanks, working.
* 67 Timer Manager for projectile complete, TakeDamage() for tank setup
* 68 Blueprintpure and Health Bar completed and working in BP
* 69 Dynamic Multicast Delegates Setup
* 70 Observer pattern, tank death complete
* 71 First person camera input complete
* 72 Spring class and BP setup. Physics contraints for springs.
* 73 SpawnPoint[SceneComponent] class created for SprungWheel
* 73B GitIgnore change
* 74 SpawnActorDeferred and FinishSpawning actor used for spawning spring
* 75 Physics contraint for spring setup in cpp
* 76 Physics constraints chained. Tank->spring->Axle->Wheel
* 77 Driving forces restructured, force applied on wheels. Added comments for revisiting the code 
* 78 Tick Groups and Physics concepts used to apply force only OnHit()
* 79 Prototype tweak and finishes

### Future Scope 
* Adding waves for enemy spawn
* Spawning enenmy as per wave difficulty 
* Adding mortar damage 
* Scoring system
