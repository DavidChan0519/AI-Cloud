#/bin/bash


function build_groupadd()
{
	(
		mkdir -p $BUILD_DIR/build_groupadd
		pushd $BUILD_DIR/build_groupadd && {
		cmake -DCMAKE_INSTALL_PREFIX=$BUILD_DIR ../../ &&
		make && make install
	} && popd
	) || print_error "build failed" $? || return $?

}


function build()
{
	build_groupadd || return $?
}

function clean()
{
	rm -rf $BUILD_DIR
}


CUR_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILD_DIR=$CUR_DIR/build

clean
build
