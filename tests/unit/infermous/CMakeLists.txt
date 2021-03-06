#####################################
# CMakeLists.txt for unit/infermous #
#####################################

###############################
# Specify the test suite name #
###############################

SET(suitename infermous)

##########################
# Specify the test names #
##########################

SET(testnames
CRFUtil
)

FOREACH(testname ${testnames})

SET(targetname "unittest_${suitename}_${testname}")

################################
# Specify the libraries to use #
################################

INCLUDE(${PROJECT_SOURCE_DIR}/cmake/UseBoost.cmake)
INCLUDE(${PROJECT_SOURCE_DIR}/cmake/UseEigen.cmake)

#############################
# Specify the project files #
#############################

SET(sources
test_${testname}.cpp
)

#############################
# Specify the source groups #
#############################

SOURCE_GROUP(sources FILES ${sources})

##########################################
# Specify additional include directories #
##########################################

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/modules/infermous/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/modules/tvgutil/include)

##########################################
# Specify the target and where to put it #
##########################################

INCLUDE(${PROJECT_SOURCE_DIR}/cmake/SetUnitTestTarget.cmake)

#################################
# Specify the libraries to link #
#################################

TARGET_LINK_LIBRARIES(${targetname} infermous tvgutil)
INCLUDE(${PROJECT_SOURCE_DIR}/cmake/LinkBoost.cmake)

ENDFOREACH()
