FROM library/postgres

ENV POSTGRES_USER=$POSTGRES_USER
ENV POSTGRES_PASSWORD=$POSTGRES_PASSWORD
ENV POSTGRES_DB=$POSTGRES_DB
WORKDIR /docker-entrypoint-initdb.d/

COPY docker-entrypoint.sh ./docker-entrypoint.sh
COPY scripts/ ./scripts/

RUN chmod +x ./docker-entrypoint.sh
ENTRYPOINT [ "./docker-entrypoint.sh" ]