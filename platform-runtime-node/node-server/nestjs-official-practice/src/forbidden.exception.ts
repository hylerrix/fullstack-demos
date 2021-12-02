import { HttpException, HttpStatus } from "@nestjs/common"

export class MyForbiddenException extends HttpException {
  constructor() {
    super('Forbidden', HttpStatus.FORBIDDEN)
  }
}