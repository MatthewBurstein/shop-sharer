FROM node:11.4

RUN set -ex

RUN mkdir /usr/src/app
WORKDIR /usr/src/app

# Copy packge files into app and install
COPY package.json ./package.json
COPY yarn.lock ./yarn.lock
RUN yarn install

# Copy public files into container
COPY index.js ./index.js

COPY docker-entrypoint.sh ./docker-entrypoint.sh
RUN chmod +x ./docker-entrypoint.sh
ENTRYPOINT ["./docker-entrypoint.sh"]
