

target_include_directories(${LF_MAIN_TARGET} PUBLIC "/${CMAKE_CURRENT_LIST_DIR}/pipeline")

target_sources(${LF_MAIN_TARGET} PUBLIC
# kernels
"${CMAKE_CURRENT_LIST_DIR}/pipeline/utils.cc"
#"${CMAKE_CURRENT_LIST_DIR}/phybench/uplink_user.cc"
)

