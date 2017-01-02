package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

import com.pi4j.io.gpio.GpioController;
import com.pi4j.io.gpio.GpioFactory;
import com.pi4j.io.gpio.GpioPinDigitalOutput;
import com.pi4j.io.gpio.PinState;
import com.pi4j.io.gpio.RaspiPin;

public class Main {
	public static void main(String[] args) throws IOException, InterruptedException {
		final GpioController gpioBuzzer = GpioFactory.getInstance();
		final GpioPinDigitalOutput buzzer = gpioBuzzer.provisionDigitalOutputPin(RaspiPin.GPIO_06, "Buzzer",
				PinState.LOW);
		buzzer.low();

		ServerSocket welcomeSocket = new ServerSocket(8000);

		while (true) {
			Socket connectionSocket = welcomeSocket.accept();
			BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
			String message = inFromClient.readLine();
			if (message.equalsIgnoreCase("open")) {
				buzzer.high();
				Thread.sleep(2000);
				buzzer.low();
			}
		}
	}
}
