using UnityEngine;

public class ParticleController : MonoBehaviour
{
    public ParticleSystem particleSystem;
    public float moveThreshold = 0.1f;

    private Vector3 lastPosition;
    private ParticleSystem.MainModule mainModule;

    void Start()
    {
        lastPosition = transform.position;
        mainModule = particleSystem.main;
    }

    void Update()
    {
        particleSystem.transform.transform.position = transform.position;
        Vector3 movement = transform.position - lastPosition;
        float speed = movement.magnitude / Time.deltaTime;

        if (speed > moveThreshold)
        {
            mainModule.startSpeed = speed;
            particleSystem.transform.rotation = Quaternion.LookRotation(movement.normalized, Vector3.up);
        }
        else
        {
            mainModule.startSpeed = 0f;
        }

        lastPosition = transform.position;
    }
}