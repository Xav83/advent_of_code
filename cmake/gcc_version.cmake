function(gcc_version output_variable)
  execute_process(COMMAND gcc --version OUTPUT_VARIABLE GCC_VERSION_RAW_OUTPUT)

  string(REGEX MATCH "[0-9]+\.[0-9]+\.[0-9]" GCC_VERSION_OUTPUT
               ${GCC_VERSION_RAW_OUTPUT})

  set(${output_variable}
      ${GCC_VERSION_OUTPUT}
      PARENT_SCOPE)
endfunction()
