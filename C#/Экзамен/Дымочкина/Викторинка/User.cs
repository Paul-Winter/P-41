using Викторинка;

namespace Викторинка
{
    public class User
    {
        public string Login { get; set; } = string.Empty;
        public string Password { get; set; } = string.Empty;
        public List<QuizResult> Results { get; set; } = new List<QuizResult>();
    }
}