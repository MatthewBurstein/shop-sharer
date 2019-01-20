FROM node:11.4

RUN set -ex

# Add bs-platform path to PATH and install
RUN PATH=/usr/local/bin:$PATH
RUN yarn global add bs-platform


RUN mkdir /usr/src/app
WORKDIR /usr/src/app

# Copy packge files into app and install
COPY package.json ./package.json
COPY bsconfig.json ./bsconfig.json
COPY yarn.lock ./yarn.lock
RUN yarn install

# Copy public files into container
COPY public/ ./public/

ENV PATH /usr/src/app/node_modules/.bin:$PATH

COPY docker-entrypoint.sh ./docker-entrypoint.sh
RUN chmod +x ./docker-entrypoint.sh
ENTRYPOINT ["./docker-entrypoint.sh"]
