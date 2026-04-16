namespace AdapterUML
{
    public interface ILogger 
    {
        void Log(string message);
    }
    public class LegacyLogger 
    {
        public void WriteToFile(string timestamp, string level, string text) 
        {
            Console.WriteLine($"[{timestamp}][{level}][{text}]");
        }
    }
    public class LegacyLoggerAdapter : ILogger
    {
        private readonly LegacyLogger _legacyLogger;

        public LegacyLoggerAdapter(LegacyLogger legacyLogger)
        {
            _legacyLogger = legacyLogger;
        }

        public void Log(string message)
        {
            _legacyLogger.WriteToFile(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"),
                "INFO",message);
        }
    }
    public class OrderService
    {
        private readonly ILogger _logger;

        public OrderService(ILogger logger)
        {
            _logger = logger;
        }
        public void PlaceOrder(string item) 
        {
            _logger.Log($"Order created :{item}");
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            var legacy = new LegacyLogger();
            var adapter = new LegacyLoggerAdapter(legacy);
            var order = new OrderService(adapter);
            order.PlaceOrder("Bread");
        }
    }
}
