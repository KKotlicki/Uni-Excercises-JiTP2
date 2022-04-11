if(NOT EXISTS "C:/JTP2/zad4/fltk/cmake-build-debug/install_manifest.txt")
   message(FATAL_ERROR
      "Cannot find install manifest: \"C:/JTP2/zad4/fltk/cmake-build-debug/install_manifest.txt\"")
endif(NOT EXISTS "C:/JTP2/zad4/fltk/cmake-build-debug/install_manifest.txt")

file(READ "C:/JTP2/zad4/fltk/cmake-build-debug/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")

foreach(file ${files})
message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
   exec_program("C:/programs/CLion 2021.3.3/bin/cmake/win/bin/cmake.exe"
      ARGS "-E remove -f \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
   )
   if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
   endif(NOT "${rm_retval}" STREQUAL 0)
endforeach(file)
