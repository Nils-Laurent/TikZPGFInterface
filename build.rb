#!/usr/bin/ruby

workspace=Dir.pwd
ENV["WORKSPACE"] = workspace

build_dir="#{workspace}/output"
project_name="data_representation"

project_name_opt="-DPROJECT_NAME='#{project_name}'"
source_dir_opt="-DSOURCES_DIR='#{workspace}/src'"
common_cflags_opt="-DCOMMON_CFLAGS='-std=c++11'"
cmake_opt=" #{source_dir_opt} #{project_name_opt} #{common_cflags_opt}"

Dir.chdir(build_dir)

cmake_cmd="cmake #{cmake_opt} #{workspace}"
make_cmd="make"

puts cmake_cmd
puts `#{cmake_cmd}`
puts `#{make_cmd}`
