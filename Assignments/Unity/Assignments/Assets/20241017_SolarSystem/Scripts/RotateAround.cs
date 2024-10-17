using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class RotateAround : MonoBehaviour
{
    public GameObject Sun;

    public float orbitPeriod;
    public float rotationPeriod;
    private float orbitSpeed;
    private float rotationSpeed;

    private void Start()
    {
        orbitSpeed = 360f / (orbitPeriod * 365.25f * 24f * 3600f);
        rotationSpeed = 360f / (rotationPeriod * 365.25f * 24f * 3600f);

    }

    void Update()
    {
        transform.RotateAround(Sun.transform.position, Vector3.up, orbitSpeed * Time.deltaTime);
        transform.Rotate(Vector3.up, rotationSpeed * Time.deltaTime, Space.Self);
    }
}
