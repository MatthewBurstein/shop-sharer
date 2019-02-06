FROM node:11.4

RUN set -ex

#install sequelize cli to be able to run commands on the container
ENV PATH /usr/src/app/node_modules/.bin:$PATH
RUN yarn global add sequelize-cli

RUN mkdir /usr/src/app
WORKDIR /usr/src/app


# Copy packge files into app and install
COPY ./ ./
# Copy .sequelizerc - why doesn't this happen above?
COPY .sequelizerc ./.sequelizerc
RUN yarn install

# Copy public files into container
COPY app.js ./app.js
COPY src/ ./src

COPY docker-entrypoint.sh ./docker-entrypoint.sh
RUN chmod +x ./docker-entrypoint.sh
ENTRYPOINT ["./docker-entrypoint.sh"]
