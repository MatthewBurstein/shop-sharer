# Learning

## docker-compose

* bs-platform is installed on linux in the image. It is therefor important that yarn install is also run in the image, and that the node_modules folder the image uses is separate from node_modules in the local file system. Otherwise `docker-compose up` will throw an `exec format error` because the `bsb.exe` binary is in the wrong format.