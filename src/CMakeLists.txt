
set(incudeDir "${CMAKE_SOURCE_DIR}/include")

set(headers
        "${incudeDir}/BoxFactory.hpp"
        "${incudeDir}/CustomSineCurve.hpp"
        "${incudeDir}/MeshFactory.hpp"
        "${incudeDir}/ObjectSpawner.hpp"
        "${incudeDir}/SphereFactory.hpp"
)

set(sources
        "ObjectSpawner.cpp"
)

add_library(objectSpawner ${sources} ${headers})
target_link_libraries(objectSpawner PUBLIC threepp::threepp)
target_include_directories(objectSpawner PUBLIC ${incudeDir})
