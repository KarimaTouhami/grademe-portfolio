// Convert a thruster force from pound-force to milli-newtons (1 lbf = 4448 mN).
// A negative force is an invalid reading: return -1.
long	to_millinewtons(long pound_force)
{
	if (pound_force < 0)
    {
        return (-1);
    }
	return (pound_force * 4448);
}
