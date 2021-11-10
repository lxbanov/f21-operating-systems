## Prevention ##

Preventation strategy implies that system should be developed in the way that one of the deadlock conditions will never hold. Practically, this system is often impossible to implement. However, using such strategy will cancel any extra effort to tackle the deadlocks during runtime.
So, this strategy is the best in terms of the performance.

## Recovery ##

Recovery strategy offers different ways to tackle the already occured deadlock. The ways differ in cruelity. This strategy is the most simple to implement (no extra work required to kill one process), but it is also the most dangerous and unstable.

## Avoidance ##

Avoidance is safer option. It is simplier than prevention, but slower in terms of performance. The key idea of the strategy is predict the deadlock and manipulate resources in the way to avoid a deadlock. This prediction spends the computer resources, so that's why this strategy is slower.