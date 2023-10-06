FROM ubuntu:22.04

# Install node for asset building
RUN apt-get update && apt-get install -y socat lib32ncurses6

# Create and switch to a user called app
RUN useradd -ms /bin/bash app
WORKDIR /home/app

# Copy across dependencies and install them
RUN chown -R app:app /home/app && chmod 750 /home/app

USER app