function(uninstall_manifest manifestPath)
    file(READ "${manifestPath}" files)
    string(REGEX REPLACE "\n" ";" files "${files}")
    foreach (file ${files})
        set(fileName $ENV{DESTDIR}${file})

        if (EXISTS "${fileName}" OR IS_SYMLINK "${fileName}")
            message(STATUS "Uninstalling: ${fileName}")

            execute_process(
                COMMAND "/usr/bin/cmake" -E remove "${fileName}"
                OUTPUT_VARIABLE rm_out
                RESULT_VARIABLE rm_retval
            )

            if (NOT ${rm_retval} EQUAL 0)
                message(FATAL_ERROR "Problem when removing: ${fileName}")
            endif ()
        else ()
            message(STATUS "Does not exist: ${fileName}")
        endif ()

    endforeach ()
endfunction(uninstall_manifest)

file(GLOB install_manifests /home/rhost/Downloads/bro-2.4.1/build/install_manifest*.txt)

if (install_manifests)
    foreach (manifest ${install_manifests})
        uninstall_manifest(${manifest})
    endforeach ()
else ()
    message(FATAL_ERROR "Cannot find any install manifests in: "
                        "\"/home/rhost/Downloads/bro-2.4.1/build/install_manifest*.txt\"")
endif ()
