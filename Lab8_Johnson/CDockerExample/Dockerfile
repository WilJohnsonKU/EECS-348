# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY FootballScores.c .
# Compile the C program
RUN gcc -o FootballScores FootballScores.c
# Set the command to run when the container starts
CMD ["./FootballScores"]