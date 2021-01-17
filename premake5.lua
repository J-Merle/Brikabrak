workspace "Brikabrak"
  configurations {"Debug", "Release"}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Brikabrak"
  location "Brikabrak"
  kind "ConsoleApp"
  architecture "x64"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("obj/" .. outputdir .. "/%{prj.name}")

  files {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs {
    "./%{prj.name}/vendor/SDL2/include"
  }



  libdirs {
    "%{prj.name}/vendor/SDL2/lib"
  }

  links {"SDL2"}

  filter "system:linux"
    cppdialect "C++17"

  filter "configurations:Debug"
    symbols "on"
    defines "DEBUG"

  filter "configurations:Release"
    optimize "on"
    defines "NDEBUG"
