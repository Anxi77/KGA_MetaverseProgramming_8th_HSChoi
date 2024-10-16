using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using UnityEngine;

namespace SpaceShooter
{
    public class PlayerScript : MonoBehaviour
    {
        public float moveSpeed = 5f;
        public float boundaryXMinSize = -15.22f;
        public float boundaryXMaxSize = 15.22f;
        public float boundaryYMinSize = -18.62f;
        public float boundaryYMaxSize = 18.62f;
        float z = 0;
        public GameObject gameOverMessage;
        public Renderer target;

        private void Awake()
        {
            target = GetComponentInChildren<Renderer>();
        }
        void Update()
        {
            PlayerMove();           
        }

        private void OnTriggerEnter2D(Collider2D collision)
        {
            if (collision.CompareTag("Enemy"))
            {
                //print("Game Over");
                //GameOver();
                Destroy(collision.gameObject);
            }
        }

        public void GameOver()
        {
            gameOverMessage.SetActive(true);
            Time.timeScale = 0;
        }

        public void PlayerMove() 
        {
            float x = Input.GetAxis("Horizontal");

            float y = Input.GetAxis("Vertical");


            transform.Rotate(new Vector3(0, 0, -x * 180) * Time.deltaTime);

            transform.Translate(new Vector3(x, 0) * Time.deltaTime * moveSpeed);
             
            if (transform.position.x < boundaryXMinSize)
            {
                transform.position = new Vector3(boundaryXMinSize, transform.position.y);
            }
            else if (transform.position.x > boundaryXMaxSize)
            {
                transform.position = new Vector3(boundaryXMaxSize, transform.position.y);
            }

            transform.Translate(new Vector3(0, y) * Time.deltaTime * moveSpeed);

            if (transform.position.y < boundaryYMinSize)
            {
                transform.position = new Vector3(transform.position.x, boundaryYMinSize);

            }
            else if (transform.position.y > boundaryYMaxSize)
            {
                transform.position = new Vector3(transform.position.x, boundaryYMaxSize);
            }
        }

        
    }
}
