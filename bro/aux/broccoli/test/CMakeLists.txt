include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/../src)

add_executable(broping broping.c)
target_link_libraries(broping ${Broccoli_LIBRARY})

add_executable(broconn broconn.c)
target_link_libraries(broconn ${Broccoli_LIBRARY})

add_executable(brohose brohose.c)
target_link_libraries(brohose ${Broccoli_LIBRARY})

add_executable(broconftest broconftest.c)
target_link_libraries(broconftest ${Broccoli_LIBRARY})

add_executable(broenum broenum.c)
target_link_libraries(broenum ${Broccoli_LIBRARY})

if (BRO_PCAP_SUPPORT)
    add_executable(brosendpackets brosendpackets.c)
    target_link_libraries(brosendpackets ${Broccoli_LIBRARY} ${PCAP_LIBRARY})
endif()

add_executable(brotable brotable.c)
target_link_libraries(brotable ${Broccoli_LIBRARY})

add_executable(broccoli-v6addrs broccoli-v6addrs.c)
target_link_libraries(broccoli-v6addrs ${Broccoli_LIBRARY})

add_executable(broccoli-vectors broccoli-vectors.c)
target_link_libraries(broccoli-vectors ${Broccoli_LIBRARY})
