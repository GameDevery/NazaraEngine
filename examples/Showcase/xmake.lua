if not has_config("assimp") then
	return
end

target("Showcase")
	set_group("Examples")
	set_kind("binary")
	add_deps("NazaraAudio", "NazaraGraphics", "NazaraPhysics2D", "NazaraPhysics3D", "NazaraWidgets")
	add_deps("PluginAssimp", { links = {} })
	add_packages("entt")
	add_files("main.cpp")
	add_defines("NAZARA_ENTT")
