# [Velt Game Engine](https://velt.theodll.me)

 Velt is a 2D/3D Game Engine powered by Vulkan and inspired by Game Engines Like [Hazel](hazelengine.com), [Unity](uinty.com) and the [Source](vavtesoftware.com) Engine.

 Velt is going to have support for Vulkan and a good foundation for implementing other modern renderering APIs like Metal for native Mac Support and D3D12 for better Windows compatibillity. The ladder two will not be happening anytime soon.

### Features

 The first beta version of Velt is presumably going to release when following Features are implemented:
- Functioning 2D Vulkan Renderer
- Somewhat usable Editor
- Basic C# Scripting Engine
- Basic Audio System
- Basic Sprite Animation System
- Box2D Physics


## Compiling
 ### 1. Dependencies
 To compile Velt you're going to need following things:
 - CMake
 - A Modern C++ Compiler installed and functioning
 - The LunarG Vulkan SDK and included tools (Shader Compiler etc.)
 ### 2. Setup
 Now simply run Setup.bat or Setup.sh and it will generate the project files for you
 ### 3. Compile
  Windows:
   - Open the VS2022 SLN file
   - Hit compile
  Unix Like:
   - ```
     make all
     ´´´
  ### 4. 
  Use Velt!
