#/bin/bash


function build_faceadd()
{
	(
		mkdir -p $BUILD_DIR/build_faceadd
		pushd $BUILD_DIR/build_faceadd && {
		cmake -DCMAKE_INSTALL_PREFIX=$BUILD_DIR ../../ &&
		make && make install
	} && popd
	) || print_error "build failed" $? || return $?

}


function build()
{
	build_faceadd || return $?
}

function clean()
{
	rm -rf $BUILD_DIR
}


CUR_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILD_DIR=$CUR_DIR/build

clean
build
