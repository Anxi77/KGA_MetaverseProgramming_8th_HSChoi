using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterMovementInput : MonoBehaviour
{
    [SerializeField] MouseInput mouseInput;

    CharacterMovement characterMovement;

    private void Awake()
    {
        characterMovement = GetComponent<CharacterMovement>();
    }

    private void Update()
    {
        characterMovement.SetDestination(mouseInput.mouseInputPosition);
    }
}
