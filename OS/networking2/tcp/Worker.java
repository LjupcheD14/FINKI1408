package tcp;

import java.io.*;
import java.net.Socket;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

public class Worker extends Thread {
    private Socket socket;

    // Constructor to initialize the worker with a client socket
    public Worker(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        BufferedReader reader = null;
        BufferedWriter writer = null;

        try {
            System.out.printf("Conncected: %s:%d:\n", socket.getInetAddress(), socket.getPort());
            // Initialize reader and writer for the socket's input and output streams
            reader = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
            writer = new BufferedWriter(new OutputStreamWriter(this.socket.getOutputStream()));

            String line = null;
            if (!(line = reader.readLine()).isEmpty()) {

                if (line.equals("Handshake")) {
                    System.out.printf("Handshake made\n");
                } else {
                    System.out.printf("Handshake was not made\n");
                    socket.close();
                }

            }

            while (!(line = reader.readLine()).isEmpty()) {
                System.out.printf("New messages from %s:%d:%s\n", socket.getInetAddress(), socket.getPort(), line);
                writer.write(line);
                writer.flush();

            }
            
            socket.close();

        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            if (reader != null) {
                try {
                    socket.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if (writer != null) {
                try {
                    writer.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if (socket != null) {
                try {
                    socket.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }
}
