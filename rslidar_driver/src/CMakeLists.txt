add_library(rslidar_input input.cc)
target_link_libraries(rslidar_input
  ${catkin_LIBRARIES}
  ${libpcap_LIBRARIES})

install(TARGETS rslidar_input
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

add_library(rslidar_driver rsdriver.cpp)
target_link_libraries(rslidar_driver
  rslidar_input
  ${catkin_LIBRARIES})

install(TARGETS rslidar_driver
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

# build the nodelet version
add_library(rslidar_driver_nodelet nodelet.cc rsdriver.cpp)
target_link_libraries(rslidar_driver_nodelet
  rslidar_input
  ${catkin_LIBRARIES}
)

install(TARGETS rslidar_driver_nodelet
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

add_executable(rslidar_node rslidar_node.cpp)

if(catkin_EXPORTED_TARGETS)
  add_dependencies(rslidar_input ${catkin_EXPORTED_TARGETS})
endif()

target_link_libraries(rslidar_node
	rslidar_driver
  rslidar_input
	${catkin_LIBRARIES}
	${libpcap_LIBRARIES}
)

install(TARGETS rslidar_node
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)
