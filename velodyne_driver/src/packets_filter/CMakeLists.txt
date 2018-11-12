# build the driver node
add_executable(packets_filter_node node.cpp packets_filter.cpp)
add_dependencies(packets_filter_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(packets_filter_node
  ${catkin_LIBRARIES}
)

# build the nodelet version
add_library(packets_filter_nodelet nodelet.cpp packets_filter.cpp)
add_dependencies(packets_filter_nodelet ${catkin_EXPORTED_TARGETS})
target_link_libraries(packets_filter_nodelet
  ${catkin_LIBRARIES}
)

# install runtime files
install(TARGETS packets_filter_node
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        COMPONENT main
)
install(TARGETS packets_filter_nodelet
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)