FROM node:10

RUN set -ex

RUN mkdir ~/.npm-global
RUN PATH=~/.npm-global/bin:$PATH
RUN yarn global add bs-platform --prefix /usr/local

RUN mkdir /usr/src/app
WORKDIR /usr/src/app

COPY package.json /usr/src/app/package.json
RUN yarn install

COPY ./src ./src

ENV PATH /usr/src/app/node_modules/.bin:$PATH

RUN yarn global add react-scripts@1.1.1  --prefix /usr/local/

WORKDIR /usr/src/app/public/
COPY ./public/index.html ./index.html
RUN pwd
RUN ls

CMD ["yarn", "start"]