using System.Collections;
using System.Collections.Generic;
using UnityEditor.SceneManagement;
using UnityEngine;

public class BulletGenerator : MonoBehaviour
{
    public GameObject Bullet;
    public float fireRate = 0.5f; // �ʴ� �߻� Ƚ��
    private float nextFireTime = 0f;

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Space) && Time.time >= nextFireTime) 
        {
            Instantiate(Bullet, transform.position, transform.rotation);
            nextFireTime = Time.time + 1f / fireRate;
        }        
    }
}