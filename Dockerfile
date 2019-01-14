FROM node:6

RUN set -ex

RUN mkdir ~/.npm-global
RUN PATH=~/.npm-global/bin:$PATH
RUN npm install -g bs-platform

RUN mkdir /usr/src/app
WORKDIR /usr/src/app

COPY package.json /usr/src/app/package.json
RUN npm install

ENV PATH /usr/src/app/node_modules/.bin:$PATH

RUN npm install react-scripts@1.1.1 -g

WORKDIR /usr/src/app/public/
COPY ./public/index.html ./index.html
RUN pwd
RUN ls

CMD ["npm", "start"]