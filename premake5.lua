workspace "tetris_work"
   architecture "x64"
   startproject "tetris_sdl"

   configurations {
       "Debug",
       "Release"
   }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
LibDirs = {}

IncludeDirs["SDL"] = "tetris_sdl/vendor/SDL2/include"
IncludeDirs["spdlog"] = "tetris_sdl/vendor/spdlog/include"
LibDirs["SDL"] = "tetris_sdl/vendor/SDL2/lib/x64"

project "tetris_sdl"
    location "tetris_sdl"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "precompch.h"
    pchsource "tetris_sdl/src/precompch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }
    includedirs {
        "%{prj.name}/src",
        "%{IncludeDirs.SDL}",
        "%{IncludeDirs.spdlog}",
    }

    libdirs {
        "%{LibDirs.SDL}",
    }

    links {
        "SDL2main",
        "SDL2",
        "SDL2_image",
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        symbols "Off"
        optimize "On"

