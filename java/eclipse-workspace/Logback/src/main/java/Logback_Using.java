import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import ch.qos.logback.classic.LoggerContext;
import ch.qos.logback.classic.joran.JoranConfigurator;
import ch.qos.logback.core.joran.spi.JoranException;
import ch.qos.logback.core.util.StatusPrinter;

public class Logback_Using {
	final static Logger logger = LoggerFactory.getLogger(Logback_Using.class);

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LoggerContext lc = (LoggerContext) LoggerFactory.getILoggerFactory();

		try {
			JoranConfigurator configurator = new JoranConfigurator();
			configurator.setContext(lc);
			lc.reset();
			configurator.doConfigure(args[0]);
		} catch (JoranException e) {
			// TODO Auto-generated catch block
			//e.printStackTrace();
		}
		StatusPrinter.printInCaseOfErrorsOrWarnings(lc);
		logger.info("Entering the application");
		Logback_Using logback =new Logback_Using();
		logback.doIt();
		logger.info("exit the application");
		
	}

	private void doIt() {
		// TODO Auto-generated method stub
		logger.debug("hellow this is the first time I use Logback");
		
	}

}
