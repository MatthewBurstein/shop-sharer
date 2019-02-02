FROM node:11.4

RUN set -ex

# Add bs-platform path to PATH and install
RUN PATH=/usr/local/bin:$PATH
RUN yarn global add bs-platform

# Add reason-cli to container to enable refmt command
RUN yarn global add reason-cli@latest-linux


RUN mkdir /usr/src/app
WORKDIR /usr/src/app

# Copy packge files into app and install
COPY package.json ./package.json
COPY bsconfig.json ./bsconfig.json
COPY yarn.lock ./yarn.lock
RUN yarn install

# Copy public files into container
COPY public/ ./public/

# Copy scripts into container
COPY scripts/ ./scripts/
ENV PATH /usr/src/app/node_modules/.bin:$PATH

COPY docker-entrypoint.sh ./docker-entrypoint.sh
RUN chmod +x ./docker-entrypoint.sh
ENTRYPOINT ["./docker-entrypoint.sh"]
