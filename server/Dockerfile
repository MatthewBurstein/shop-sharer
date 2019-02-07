FROM node:11.4

RUN set -ex

#install sequelize cli to be able to run commands on the container
ENV PATH /usr/src/app/node_modules/.bin:$PATH

# install this as a dev dependency and run with yarn sequelize
RUN yarn global add sequelize-cli

RUN mkdir /usr/src/app
WORKDIR /usr/src/app

COPY docker-entrypoint.sh ./docker-entrypoint.sh
RUN chmod +x ./docker-entrypoint.sh
ENTRYPOINT ["./docker-entrypoint.sh"]