include(${CMAKE_CURRENT_LIST_DIR}/gcc_version.cmake)

function(gcc_version_for_conan gcc_version output_variable)
  if(${gcc_version} VERSION_EQUAL "12.1.0")
    set(${output_variable}
        12
        PARENT_SCOPE)
  else()
    set(${output_variable}
        ${gcc_version}
        PARENT_SCOPE)
  endif()
endfunction()

function(conan_install conanfile_location_folder)
  gcc_version(GCC_VERSION)
  gcc_version_for_conan(${GCC_VERSION} CONAN_GCC_VERSION)
  execute_process(
    COMMAND
      conan install . --install-folder=build -pr=.conan/linux_profile
      --build=missing -s build_type=Debug -s
      compiler.version=${CONAN_GCC_VERSION}
    WORKING_DIRECTORY ${conanfile_location_folder})
  execute_process(
    COMMAND
      conan install . --install-folder=build -pr=.conan/linux_profile
      --build=missing -s build_type=Release -s
      compiler.version=${CONAN_GCC_VERSION}
    WORKING_DIRECTORY ${conanfile_location_folder})
endfunction()
