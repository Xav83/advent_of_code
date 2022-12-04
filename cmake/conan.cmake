function(conan_install conanfile_location_folder)
  execute_process(
    COMMAND conan install . --install-folder=build -pr=.conan/linux_profile
            --build=missing -s build_type=Debug
    WORKING_DIRECTORY ${conanfile_location_folder})
  execute_process(
    COMMAND conan install . --install-folder=build -pr=.conan/linux_profile
            --build=missing -s build_type=Release
    WORKING_DIRECTORY ${conanfile_location_folder})
endfunction()
