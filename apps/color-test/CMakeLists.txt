add_executable(color-test)
target_sources(color-test
    PRIVATE
        src/main.cpp
        src/palette.cpp
        src/swatch.cpp
)
target_include_directories(color-test PRIVATE src)
target_link_libraries(color-test PRIVATE m raylib)

# Copy each font into the target directory after build
set(FONTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/resources/")

set(FONT_FILES
    "SourceCodePro-Regular.ttf"
)

foreach(font ${FONT_FILES})
  add_custom_command(TARGET color-test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${FONTS_DIR}/${font}"
      $<TARGET_FILE_DIR:color-test>/${font}
  )
endforeach()

# Set a preprocessor definition for the font folder
target_compile_definitions(color-test PRIVATE
  FONT_RUNTIME_DIR="$<TARGET_FILE_DIR:color-test>"
)