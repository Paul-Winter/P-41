using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.Shapes;
using Avalonia.Input;
using Avalonia.Metadata;
using Avalonia.Threading;
using System;
using System.Collections.Generic;


namespace AvaloniaApplication1.Views
{
    public partial class MainWindow : Window
    {
        private const double Speed = 220;
        private readonly HashSet<Key> _pressed = new();
        private List<Rect> _obstacle = null!;
        public MainWindow()
        {
            InitializeComponent();
            _obstacle = new List<Rect>
            {
                ToRect(Obstacle1),
                ToRect(Obstacle2)
            };
            var timer = new DispatcherTimer
            {
                Interval = TimeSpan.FromMilliseconds(16)
            };
            timer.Tick += OnTick;
            timer.Start();

        }

        private static Rect ToRect(Rectangle r)
        {
            return new(Canvas.GetLeft(r), Canvas.GetTop(r), r.Width, r.Height);
        }

        private bool Collides(double x, double y)
        {
            var playerRect = new Rect(x,y,Player.Width,Player.Height);
            foreach (var obstacle in _obstacle)
            {
                if (playerRect.Intersects(obstacle))
                {
                    return true;
                }
            }
            return false;
        }
        private void OnKeyDown(object? sender,KeyEventArgs e) => _pressed.Add(e.Key);

        private void OnKeyUp(object? sender, KeyEventArgs e) => _pressed.Remove(e.Key);

        private void OnTick(object? sender, EventArgs e)
        {
            const double dt = 0.016;
            double dx = 0, dy = 0;

            if (_pressed.Contains(Key.W)) dy -= 1;
            if (_pressed.Contains(Key.S)) dy += 1;
            if (_pressed.Contains(Key.A)) dx -= 1;
            if (_pressed.Contains(Key.D)) dx += 1;

            if (dx == 0 && dy == 0) return;

            double len = Math.Sqrt(dx * dx + dy * dy);
            dx /= len;
            dy /= len;

            double curX = Canvas.GetLeft(Player);
            double curY = Canvas.GetTop(Player);

            double newX = curX + dx * Speed * dt;
            double newY = curY + dy * Speed * dt;

            if (!Collides(newX, curY))
                curX = newX;
            if(!Collides(curX,newY))
                curY= newY;

            curX = Math.Clamp(curX, 0, Field.Width - Player.Width);
            curY = Math.Clamp(curY, 0, Field.Height - Player.Height);


            Canvas.SetLeft(Player, curX);
            Canvas.SetTop(Player, curY);
        }
    }
}