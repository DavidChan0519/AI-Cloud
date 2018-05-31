#/bin/bash


function build_face_detect()
{
	(
		mkdir -p $BUILD_DIR/face_detect
		pushd $BUILD_DIR/face_detect && {
		cmake -DCMAKE_INSTALL_PREFIX=$BUILD_DIR ../../ &&
		make && make install
	} && popd
	) || print_error "build failed" $? || return $?

}


function build()
{
	build_face_detect || return $?
}

function clean()
{
	rm -rf $BUILD_DIR
}


CUR_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILD_DIR=$CUR_DIR/build

clean
build
